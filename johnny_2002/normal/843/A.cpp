#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

#define X first
#define Y second


const int N=2e5+10;

int n,h[N];
ii a[N];
vector <int> v[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i].X);
        a[i].Y=i;
    }
    sort(a+1,a+n+1);
    int ans=0;
    for(int st=1;st<=n;st++) if (!h[st]){
        int cur=st;
        ++ans;
        while (!h[cur]){
            v[ans].push_back(cur);
            h[cur]=1;
            cur=a[cur].Y;
        }
    }
    cout<<ans<<'\n';
    for(int i=1;i<=ans;i++){
        cout<<v[i].size()<<" ";
        for(auto j:v[i]) cout<<j<<" ";
        cout<<'\n';
    }
}