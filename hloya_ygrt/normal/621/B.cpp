#include<bits/stdc++.h>


using namespace std;

#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pair
const int maxn = 1e3 + 5, inf = 2e9;
    bool a[maxn][maxn];

    vector<pair<int,int> > pos;

int main()
{
  //  freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
    int  n;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for (int i=0;i<n;i++)
    {
       int x,y;
       scanf("%d %d",&x,&y);
       //swap(x,y);
        a[x][y] = 1;
    }
    pos.push_back(mp(1,1));
    ll ans = 0;
    vector<pair<int,int> > tmp;
    for (int i=0;i<=5000;i++){
        ll cnt = 0;

        for (int j=0;j<pos.size();j++){
            if (a[pos[j].f][pos[j].s] == 1)
                {
                    cnt++;
               //     cerr<<pos[j].f<<' '<<pos[j].s<<'\n';
                }
            if (pos[j].s == 1)
                tmp.push_back(mp(pos[j].f+1,1));
            tmp.push_back(mp(pos[j].f,pos[j].s+1));
        }
        pos.clear();
        for (int i=0;i<tmp.size();i++){
            if (tmp[i].f<=1000&&tmp[i].s<=1000)
                pos.push_back(tmp[i]);
        }
        tmp.clear();
        ans += (1LL*cnt*1LL*(cnt-1))/2LL;
    }
    pos.clear();
    tmp.clear();
    pos.push_back(mp(1000,1));
    for (int i=0;i<=5000;i++){
        ll cnt = 0;
        for (int j=0;j<pos.size();j++){
         //   cerr<<pos[i].f<<' '<<pos[i].s<<endl;
            //cerr<<pos[j].f<<' '<<pos[j].s<<'\n';
           // if (pos[j].f==1&&pos[j].s==5)
           //     cerr<<"I K";
            if (a[pos[j].f][pos[j].s] == 1)
                {

                    cnt++;
                }
            if (pos[j].f == 1000)
                tmp.push_back(mp(pos[j].f,pos[j].s+1));
            tmp.push_back(mp(pos[j].f-1,pos[j].s));
        }
        pos.clear();
        for (int i=0;i<tmp.size();i++){
         if (tmp[i].f>=1&&tmp[i].s<=1000)
                pos.push_back(tmp[i]);
        }
        tmp.clear();
        ans += (1LL*cnt*1LL*(cnt-1))/2LL;
    }
    cout<<ans;
    return 0;
}