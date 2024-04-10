#include<bits/stdc++.h>
#define MAX   300300
#define BLOCK   2000
#define INSERT   1
#define DELETE   2
#define ASK   3
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
const int INF=(int)1e9+7;
const long long LLINF=2LL*INF*INF;
const string emptySet="EMPTY SET";
int ceil(int b,int a) {
    while (a==0) cout<<"FUCK"<<endl;
    if (a<0) return (ceil(-b,-a));
    if (b>=0) return (b/a+(b%a!=0));
    if (b%a==0) return (b/a);
    return (-((-b)/a));
}
class ConvexHull {
    private:
    struct Segment {
        int x,a,b;
        Segment() {
            x=a=b=0;
        }
        Segment(int _x,int _a,int _b) {
            x=_x;a=_a;b=_b;
        }
        long long y(void) const {
            return (1LL*a*x+b);
        }
    };
    vector<Segment> segments;
    public:
    void addLine(int a,int b) {
        while (!segments.empty() && segments.back().y()<=1LL*a*segments.back().x+b)
            segments.pop_back();
        if (segments.empty()) {
            segments.push_back(Segment(-INF,a,b));
            return;
        }
        long long x=ceil(b-segments.back().b,segments.back().a-a);
        if (x>INF) return;
        segments.push_back(Segment(x,a,b));
    }
    long long query(int x) {
        while (!segments.empty() && segments.back().x>x) segments.pop_back();
        if (segments.empty()) return (-LLINF);
        int a=segments.back().a;
        int b=segments.back().b;
        return (1LL*a*x+b);
    }
};
struct Query {
    int type,x,y,id;
    Query() {
        type=x=y=id=0;
    }
    void input(int id) {
        this->id=id;
        scanf("%d%d",&type,&x);
        if (type==INSERT) scanf("%d",&y);
    }
};
typedef pair<int,int> Line;
Line allLines[MAX];
set<pair<Line,int> > lines;
vector<pair<Line,int> > recentLines;
int numQuery,curQuery,lastInsert;
bool deleted[MAX];
vector<Query> queries;
vector<ConvexHull> convexHulls;
vector<int> willDelete;
vector<pair<int,int> > askQueries;
long long answer[MAX];
void readNextQuery(void) {
    while (queries.size()<BLOCK && curQuery<numQuery) {
        curQuery++;
        Query query; query.input(curQuery);
        queries.push_back(query);
    }
}
void prepareQuery(void) {
    FORE(it,queries) {
        if (it->type==DELETE && it->x<=lastInsert)
            willDelete.push_back(it->x);
        if (it->type==ASK) askQueries.push_back(make_pair(it->x,it->id));
    }
    sort(ALL(willDelete));
    FORE(it,lines) {
        if (binary_search(ALL(willDelete),it->se)) convexHulls.push_back(ConvexHull());
        else {
            if (convexHulls.empty()) convexHulls.push_back(ConvexHull());
            convexHulls.back().addLine(it->fi.fi,it->fi.se);
        }
    }
}
void insertLine(const Query &q) {
    lastInsert=q.id;
    recentLines.push_back(make_pair(Line(q.x,q.y),q.id));
    lines.insert(make_pair(Line(q.x,q.y),q.id));
    allLines[q.id]=make_pair(q.x,q.y);
}
void deleteLine(const Query &q) {
    deleted[q.x]=true;
    int x=allLines[q.x].fi;
    int y=allLines[q.x].se;
    lines.erase(make_pair(Line(x,y),q.x));
}
void processQuery(void) {
    sort(ALL(askQueries),greater<pair<int,int> >());
    FORE(it,convexHulls) FORE(jt,askQueries)
        maximize(answer[jt->se],it->query(jt->fi));
    FORE(it,queries) {
        if (it->type==ASK) {
            int x=it->x;
            FORE(jt,willDelete) if (!deleted[*jt]) {
                int a=allLines[*jt].fi;
                int b=allLines[*jt].se;
                maximize(answer[it->id],1LL*x*a+b);
            }
            FORE(jt,recentLines) if (!deleted[jt->se]) {
                int a=jt->fi.fi;
                int b=jt->fi.se;
                maximize(answer[it->id],1LL*x*a+b);
            }
            if (answer[it->id]==-LLINF) answer[it->id]=LLINF;
        }
        if (it->type==INSERT) insertLine(*it);
        if (it->type==DELETE) deleteLine(*it);
    }
}
void afterProcess(void) {
    queries.clear();
    convexHulls.clear();
    recentLines.clear();
    willDelete.clear();
    askQueries.clear();
}
void process(void) {
    scanf("%d",&numQuery);
    FOR(i,1,numQuery) answer[i]=-LLINF;
    while (curQuery<numQuery) {
        readNextQuery();
        //printf("XXX\n");
        prepareQuery();
        //printf("YYY\n");
        processQuery();
        //printf("ZZZ\n");
        afterProcess();
        //printf("TTT\n");
    }
    FOR(i,1,numQuery) if (answer[i]>-LLINF) {
        if (answer[i]<LLINF) printf("%I64d\n",answer[i]);
        else printf("%s\n",emptySet.c_str());
    }
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    process();
    return 0;
}