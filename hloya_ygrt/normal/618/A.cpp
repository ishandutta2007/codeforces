#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define ll long long

const int maxn = 1e5+5, inf = 2e9;

    int bad[maxn];
int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> step;
    int s= 1;
    while (n){
        step.push_back(n&1);
        n>>=1;
    }
    for (int i=step.size()-1;i>=0;i--){
        bad[i] = s;
        s*=2;
    }
    vector<int> ans;
    //reverse(step.begin(),step.end());
    for (int i=0;i<step.size();i++){
        if (step[i]){
            ans.push_back(i+1);
        }
    }
    for (int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<' ';
    return 0;
}