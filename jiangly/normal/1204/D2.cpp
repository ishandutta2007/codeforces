#include<bits/stdc++.h>
using namespace std;
constexpr int INF=1e9;
class Solver{
private:
    static constexpr int MAX_N=1e5;
    string s;
    int n;
    int a[MAX_N];
    int b[MAX_N];
public:
    void solve(){
        cin>>s;
        n=s.length();
        for(int i=0;i<n;++i){
            a[i]=s[i]-'0';
        }
        int last=n;
        for(int i=n-1;i>=0;--i){
            if(a[i]==0){
                b[i]=0;
            }else{
                int l_a[]={0,1};
                int l_b[]={1,0};
                bool ok=true;
                for(int j=i+1;j<last;++j){
                    if(a[j]==0){
                        ++l_a[0];
                        ++l_b[0];
                    }else{
                        l_a[1]=max(l_a[1],l_a[0])+1;
                        l_b[1]=max(l_b[1],l_b[0])+1;
                    }
                    if(max(l_a[0],l_a[1])!=max(l_b[0],l_b[1])){
                        ok=false;
                        break;
                    }
                }
                if(ok){
                    b[i]=0;
                    last=i;
                }else{
                    b[i]=1;
                }
            }
        }
        for(int i=0;i<n;++i){
            cout<<b[i];
        }
        cout<<endl;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solver().solve();
    return 0;
}