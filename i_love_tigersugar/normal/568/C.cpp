#include<bits/stdc++.h>
#define MAX   404
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define VOWEL(x) (x)
#define CONSO(x) ((x)+n)
#define INV(x) ((x)>n?(x)-n:(x)+n)
using namespace std;
int n,m,q;
bool vowel[MAX];
char s[MAX];
bool need[MAX][MAX];
int curState[MAX];
bool canVowel[MAX],canConso[MAX];
void init(void) {
    scanf("%s",s);
    q=strlen(s);
    REP(i,q) vowel[i]=s[i]=='V';
    scanf("%d%d",&n,&m);
    REP(love,m) {
        char u[2],v[2];
        int x,y;
        scanf("%d%s%d%s",&x,u,&y,v);
        int a=u[0]=='V'?VOWEL(x):CONSO(x);
        int b=v[0]=='V'?VOWEL(y):CONSO(y);
        need[a][b]=true;
        need[INV(b)][INV(a)]=true;
    }
    scanf("%s",s+1);
    s[0]=0;
}
void warshall(void) {
    FOR(i,1,2*n) need[i][i]=true;
    FOR(k,1,2*n) FOR(i,1,2*n) FOR(j,1,2*n)
        if (need[i][k] && need[k][j]) need[i][j]=true;
    FOR(i,1,n) {
        canVowel[i]=canConso[i]=true;
        if (need[VOWEL(i)][CONSO(i)]) canVowel[i]=false;
        if (need[CONSO(i)][VOWEL(i)]) canConso[i]=false;
        FOR(j,1,n) if (i!=j && need[VOWEL(i)][VOWEL(j)] && need[VOWEL(i)][CONSO(j)]) canVowel[i]=false;
        FOR(j,1,n) if (i!=j && need[CONSO(i)][VOWEL(j)] && need[CONSO(i)][CONSO(j)]) canConso[i]=false;
    }
}
bool checkVowel(int pos) {
    if (curState[pos]==0) return (false);
    if (!canVowel[pos]) return (false);
    FOR(i,1,n) if (i!=pos) {
        if (need[VOWEL(pos)][VOWEL(i)] && curState[i]==0) return (false);
        if (need[VOWEL(pos)][CONSO(i)] && curState[i]==1) return (false);
    }
    return (true);
}
bool checkConso(int pos) {
    if (curState[pos]==1) return (false);
    if (!canConso[pos]) return (false);
    FOR(i,1,n) if (i!=pos) {
        if (need[CONSO(pos)][VOWEL(i)] && curState[i]==0) return (false);
        if (need[CONSO(pos)][CONSO(i)] && curState[i]==1) return (false);
    }
    return (true);
}
void fixVowel(int pos) {
    curState[pos]=1;
    FOR(i,1,n) if (i!=pos) {
        if (need[VOWEL(pos)][VOWEL(i)]) curState[i]=1;
        if (need[VOWEL(pos)][CONSO(i)]) curState[i]=0;
    }
}
void fixConso(int pos) {
    curState[pos]=0;
    FOR(i,1,n) if (i!=pos) {
        if (need[CONSO(pos)][VOWEL(i)]) curState[i]=1;
        if (need[CONSO(pos)][CONSO(i)]) curState[i]=0;
    }
}
string checkPrefix(int len) {
    memset(curState,-1,sizeof curState);
    FOR(i,1,len) {
        if (vowel[s[i]-'a']) {
            if (!checkVowel(i)) return ("");
            fixVowel(i);
        } else {
            if (!checkConso(i)) return ("");
            fixConso(i);
        }
    }
    string res;
    FOR(i,1,len) res.push_back(s[i]);
    FOR(i,len+1,n) {
        char minV=-1;
        char minC=-1;
        FOR(j,i==len+1?s[i]+1:'a','a'+q-1) {
            if (vowel[j-'a']) {
                if (minV<0) minV=j;
            } else {
                if (minC<0) minC=j;
            }
        }
        set<char> can;
        if (minV>=0) can.insert(minV);
        if (minC>=0) can.insert(minC);
        bool ok=false;
        FORE(it,can) {
            bool canPut=vowel[*it-'a']?checkVowel(i):checkConso(i);
            if (canPut) {
                if (vowel[*it-'a']) fixVowel(i); else fixConso(i);
                res.push_back(*it);
                ok=true;
                break;
            }
        }
        if (!ok) return ("");
    }
    return (res);
}
void process(void) {
    FORD(i,n,0) {
        string tmp=checkPrefix(i);
        if (!tmp.empty()) {
            cout<<tmp<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}
int main(void) {
    init();
    warshall();
    process();
    return 0;
}