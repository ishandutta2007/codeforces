#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define exp fgfdgd
const int N = 5E5+7;
int A[N];
int F(int pos){
    A[pos] = A[pos+1] = A[pos+2] = A[pos]^A[pos+1]^A[pos+2];
}
void solve(){
    int n;
    cin>>n;
    int pos = 0;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        if (A[i]==0)
            pos = i;
    }
    int start = 1;
    vector<int> ans;
    for(int i = 1;i<=n;++i){
        if (A[i]==0){
            if (start==i){
                ++start;
                continue;
            }
            else if ((i-start)%2==0){
                int cur = i-2;
                while(cur>=start){
                    F(cur);
                    ans.push_back(cur);
                    cur-=2;
                }
                start = i+1;
            }
            else if (A[i+1]==1 && i+1<=n){

                int cur = i-1;
                while(cur>=start){
                    F(cur);
                    ans.push_back(cur);
                    cur-=2;
                }
                start = i+1;
            }
            else{
                int cur = i;
                while(A[cur+1]==0 && cur+1<=n){
                    F(cur-1);
                    ans.push_back(cur-1);
                    cur+=2;
                }
            }
        }
        else{
            continue;
        }
    }
    start = n;
    for(int i = n;i>=1;--i){
        if (A[i]==0){
            if (start==i){
                --start;
                continue;
            }
            else if ((start-i)%2==0){
                int cur = i;
                while(cur+2<=start){
                    ans.push_back(cur);
                    F(cur);
                    cur+=2;
                }
                start = i-1;
            }
            else if (A[i-1]==1 && i-1>=1){
                A[i] = A[i-1] = 0;
                int cur = i-1;
                while(cur+2<=start){
                    ans.push_back(cur);
                    F(cur);
                    cur+=2;
                }
                start = i-1;
            }
            else{
                int cur = i;
                while(A[cur-1]==0 && A[cur-2]==0 && cur-2>=1){
                    ans.push_back(cur-2);
                    F(cur-2);
                    cur-=2;
                }
            }
        }
        else{
            continue;
        }
    }
    int flag = 0;
    for(int i = 1;i<=n;++i){
        if (A[i]){
            flag = 1;
            break;
        }
    }
    if (flag){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        cout<<ans.size()<<endl;
        for(int to:ans)
            cout<<to<<' ';
        cout<<endl;
    }


}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}