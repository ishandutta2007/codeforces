#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define ll long long

const int maxn = 1e5, inf = 2e9;
    int a[60][60];
    bool used[60]={0};
    int n;

    pair<int,int> get_min(){
        int _mn = inf,ans;
        for (int j=0;j<n;j++){
            int found=inf;
            bool good = 1;
            if (used[j])
                continue;
            for (int i=0;i<n;i++)
            {
                if (used[i])
                    continue;
                if (a[i][j]==0)
                    continue;
                if (found == inf ){
                    found = a[i][j];
                }
                if (a[i][j] != found)
                {
                    good = 0;
                    break;
                }
            }
            if (good){
                if (_mn > found){
                    _mn = found;
                    ans = j;
                }
            }
        }
        if (_mn==inf)
            return mp(inf,inf);
        else
            return mp(_mn,ans);
    }
int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);

    scanf("%d",&n);
    int ans[51];
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    for (int i=0;i<n;i++)
        ans[i] = inf;
    vector<int> p;
    for (int k=0;k<n;k++){
        pair<int,int> _mn = get_min();
        if (_mn.s==inf)
            break;
        used[_mn.s] = 1;
        ans[_mn.s] = _mn.f;
        p.pb(_mn.f);
    }
    sort(p.begin(),p.end());
    int ost = p.back() + 1;
    if (p.front()!=1)
        ost = 1;
    for (int i=1;i<p.size();i++){
        if (p[i] - p[i-1]!=1){
            ost = p[i] - 1;
        }
    }
    for(int i=0;i<n;i++)
       {if (ans[i] == inf){
        ans[i] = ost;
       }
       cout<<ans[i]<<' ';
}
    return 0;
}