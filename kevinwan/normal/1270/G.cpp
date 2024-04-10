#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int mn=1e6+10;
int a[mn];
bool ins[mn];
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",a+i),a[i]=i-a[i],ins[i]=0;
        stack<int>s;
        s.push(1);
        ins[1]=1;
        vector<int>ans;
        while(s.size()){
            int x=s.top();
            int y=a[x];
            if(ins[y]){
                ans.push_back(y);
                while(s.top()!=y)ans.push_back(s.top()),s.pop();
                break;
            }
            else{
                ins[y]=1;
                s.push(y);
            }
        }
        printf("%d\n",ans.size());
        for(int x:ans)printf("%d ",x);
        printf("\n");
    }
}