#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define pb push_back
 
typedef long long ll;
typedef pair<int, int> pii;
 
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e5+10;
const ll MOD = 1e9+7;

int ask(bool tp, int i){
    cout<<tp+1<<" "<<i+1<<endl;
    int x;
    cin>>x;
    return x;
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    srand(time(NULL));

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<bool> s(n);
        s[0]=0;
        if(n>1)s[1]=ask(1,1);

        if(s[1]==s[0]){
            for(int i=2;i<s.size();i+=2){
                if(i==s.size()-1){
                    int x=ask(0,i);
                    if(x==0)s[i]=1;
                    else s[i]=s[x-1];
                    break;
                }
                bool sla=rand()%2;
                int vv=ask(sla,i+1);
                //prefix function
                if(sla==0){
                    if(vv>=2){
                        s[i]=s[vv-2];
                        s[i+1]=s[vv-1];
                    }
                    if(vv==1){
                        s[i]=1;
                        s[i+1]=0;
                    }
                    if(vv==0){
                        s[i+1]=1;
                        int x=ask(0,i);
                        if(x==0)s[i]=1;
                        else s[i]=s[x-1];
                    }
                }
                else{
                    if(vv>=2){
                        s[i]=!s[vv-2];
                        s[i+1]=!s[vv-1];
                    }
                    if(vv==1){
                        s[i]=0;
                        s[i+1]=1;
                    }
                    if(vv==0){
                        s[i+1]=0;
                        int x=ask(0,i);
                        if(x==0)s[i]=1;
                        else s[i]=s[x-1];
                    }
                }
            }

        }
        else{
            //01
            for(int i=2;i<s.size();i+=2){
                if(i==s.size()-1){
                    int x=ask(0,i);
                    if(x==0)s[i]=1;
                    else s[i]=s[x-1];
                    break;
                }
                bool sla=rand()%2;
                int vv=ask(sla,i+1);
                //prefix function
                if(sla==0){
                    if(vv>=2){
                        s[i]=s[vv-2];
                        s[i+1]=s[vv-1];
                    }
                    if(vv==1){
                        s[i+1]=0;
                        int x=ask(0,i);
                        if(x==0)s[i]=1;
                        else s[i]=s[x-1];
                    }
                    if(vv==0){
                        s[i]=1;
                        s[i+1]=1;
                    }
                }
                else{
                    if(vv>=2){
                        s[i]=!s[vv-2];
                        s[i+1]=!s[vv-1];
                    }
                    if(vv==1){
                        s[i+1]=1;
                        int x=ask(0,i);
                        if(x==0)s[i]=1;
                        else s[i]=s[x-1];
                    }
                    if(vv==0){
                        s[i]=0;
                        s[i+1]=0;
                    }
                }
            }
        }

        cout<<0<<" ";
        for(auto x:s)cout<<x;
        cout<<endl;
        int x;
        cin>>x;


    }
    return 0;
}