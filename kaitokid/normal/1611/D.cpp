#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int b[200009],p[200009],ans[200009];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){cin>>b[i];ans[i]=-1;if(i==b[i])ans[i]=0;}
    for(int i=0;i<n;i++)
    cin>>p[i];
    if(b[p[0]]!=p[0]){cout<<-1<<endl;continue;}
    bool bl=true;
    for(int i=0;i<n;i++)
    {
        int u=p[i];
        if(ans[b[u]]==-1){bl=false;break;}
        ans[u]=i;
    }
    if(bl==false){cout<<-1<<endl;continue;}
    for(int i=1;i<=n;i++)
    {
        if(i==b[i]){cout<<0<<" ";continue;}
        cout<<ans[i]-ans[b[i]]<<" ";
    }
    cout<<endl;
}
	return 0;
}