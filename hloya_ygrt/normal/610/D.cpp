using namespace std;
#include <bits/stdc++.h>

const int maxn=4e5;
const int inf=2e9;
const int eps=1e-6;
const int base=1e1;
#define mp make_pair
#define f first
#define sec second
#define pb push_back
#define ll long long
#define ld long double
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)
int t[maxn*2] , sx = 1;
int sum(int r)
{
    int res = 0;
    while (r>0)
    {
        res+=t[r];
        r-=r&(-r);
    }
    return res;
}

void add(int i,int x)
{
    while (i<=sx)
    {
        t[i]+=x;
        i+=i&(-i);
    }
}
struct lnx
{
    int x1,x2,y;
    lnx(){}
    lnx(int x1,int x2,int y):x1(x1),x2(x2),y(y){}
    bool operator < (const lnx &T) const
    {
        if (y<T.y)
            return 1;
        if (y>T.y)
            return 0;
        return x1<=T.x1;
    }
};

struct lny
{
    int y,x;
    bool t;
    lny(){}
    lny(int _y,int _x,bool _t)
    {
        t = _t;
        x = _x;
        y = _y;
    }
    bool operator < (const lny &T) const
    {
        if (y<T.y)
            return 1;
        if (y>T.y)
            return 0;
        if (t!=T.t)
            return !t;
        return x<=T.x;
    }
};
//vector<pair<pair<int,int>,pair<int,int> > > input;


vector<lny> events2;
vector<int> compression;
map<int,int> sot;
vector<lnx> events1;
vector<lnx> bad1,bad2;
bool used[maxn];
vector<lnx> fix(vector<lnx> bad,bool n = 0)
{
    memset(used,0,sizeof(used));
    int l,r;
    l = 0;
    r = 1;
  //  for (int i=0;i<bad.size();i++)
   //     //cerr<<bad[i].x1<<' '<<bad[i].x2<<' '<<bad[i].y<<endl;
    while (r<bad.size())
    {
        while (r<bad.size()&&bad[r].y==bad[l].y){
            if (bad[l].x2>=bad[r].x2){
                used[r] = 1;
             //   bad[l].x2 = bad[r].x2;
                r++;
                continue;
            }
            if (bad[l].x1<=bad[r].x1&&bad[l].x2>=bad[r].x1){
                used[r] = 1;
                bad[l].x2 = bad[r].x2;
                r++;
            } else{
                l++;
                if (l==r)
                    r++;
        }
        }
        l = r;
        r = l+1;
    }
    vector<lnx> ans;
    for (int i=0;i<bad.size();i++)
        if (!used[i]){
            if (!n){
        //        cout<<bad[i].x1<<' '<<bad[i].y<<' '<<bad[i].x2<<' '<<bad[i].y<<endl;
            } else
            {
          //      <<bad[i].y<<' '<<bad[i].x1<<' '<<bad[i].y<<' '<<bad[i].x2<<endl;
            }
                ans.pb(bad[i]);
            }
      //  //cerr<<"v"<<endl;
    return ans;
}
int main()
{
   // freopen("output.txt","w",stdout);
    //fast_io;
    //freopen("input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    ll ans = 0;
    for (int i=0;i<n;i++){
        int x1,x2,y1,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if (x1>x2)
            swap(x1,x2);
        if (y1>y2)
            swap(y1,y2);
       // ans+=(x2-x1+1)*(y2-y1+1);
       // input.pb(mp(mp(x1,y1),mp(x2,y2)));
       /*if (y1 == y2){
            events1.pb(lnx(x1,x2,y));
        } else
        {
            events2.pb(lny(y1,x1,0));
            events2.pb(lny(y2,x2,1));
        }*/
        compression.pb(x1);
        if(x1!=x2)
            compression.pb(x2);

        if (y1 == y2)
            bad1.pb(lnx(x1,x2,y1));
        else
            bad2.pb(lnx(y1,y2,x1));
    }
    sort(bad1.begin(),bad1.end());
    sort(bad2.begin(),bad2.end());
    bad1 = fix(bad1);
    bad2 = fix(bad2,1);
   // ////cerr<<bad1.size()+bad2.size()<<endl;
    for (int i=0;i<bad1.size();i++){
       // ////cerr<<bad1[i].x1<<' '<<bad1[i].x2;

        ans += bad1[i].x2 - bad1[i].x1 + 1;
        events1.pb(bad1[i]);
    }

    for (int i=0;i<bad2.size();i++){
       // ////cerr<<bad2[i].x1<<' '<<bad2[i].x2;
        ans += bad2[i].x2 - bad2[i].x1 + 1;
        int y1=bad2[i].x1,y2=bad2[i].x2,x=bad2[i].y;
        events2.pb(lny(y1,x,0));
        events2.pb(lny(y2,x,1));
    }
   // ////cerr<<ans<<endl;
    sort(events1.begin(),events1.end());
    sort(events2.begin(),events2.end());
    sort(compression.begin(),compression.end());


    for (int i=0;i<compression.size();i++){
        if (sot.find(compression[i])!=sot.end())
            continue;
        sot[compression[i]] = sx;
        ////cerr<<compression[i]<<'='<<sx<<endl;
        sx++;
    }

    int le1,le2;
    le1 = le2 = 0;
   /* for (int i=0;i<events1.size();i++)
        ////cerr<<"X1="<<events1[i].x1<<" X2="<<events1[i].x2<<" Y="<<events1[i].y<<endl;
  */  for (int i=0;i<events2.size();i++)
    {
          //  if (events2[i].t==0)
                //cerr<<"OPENED:";
        //    else
            //cerr<<"CLOSED:";
        //cerr<<events2[i].x<<' '<<events2[i].y<<endl;
    }


    while (le1<events1.size()&&le2<events2.size())
    {
        int y1 = events1[le1].y;
        ////cerr<<events1[le1].x1<<' '<<events1[le1].x2<<' '<<events1[le1].y<<endl;
        int s = 0;
        while (le2<events2.size())
        {
            int y2 = events2[le2].y;
            if (y2 > y1)
                break;
            if (events2[le2].t== 0){
                add(sot[events2[le2].x],1);
            } else{
                if (y2 < y1)
                    add(sot[events2[le2].x],-1);
                else
                {
                    if (events2[le2].x>events1[le1].x2)
                        break;
                    if (events2[le2].x<events1[le1].x1)
                        add(sot[events2[le2].x],-1);
                    else
                    {
                        add(sot[events2[le2].x],-1);
                        s++;
                    }
                }
            }
            le2++;
        }

        s += sum(sot[events1[le1].x2]);
        s -= sum(sot[events1[le1].x1]-1);
        ans-=s;
       /* while (le2<events2.size()&&events2[le2].t == 1){
            if (events2[le2].y<=y1){
                    add(sot[events2[le2].x],-1);
            } else
                break;
            le2++;
        }*/
        le1++;
    }

    cout<<ans;
  /*  for (int i=0;i<events1.size();i++)
        //cerr << events1[i].x1<< ' '<<events1[i].x2<<' '<<events1[i].y<<endl;
    for (int i=0;i<events2.size();i++)
        //cerr << events2[i].x<<' '<<events2[i].y<<' '<<events2[i].t<<endl;*/

    return 0;
}