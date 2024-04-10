#pragma GCC Optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//#define endl '\n'
const int N = 1e5+7;
int ask(int p1,int p2,int type){
    if (type==0)
        cout<<"or ";
    else cout<<"and ";
    cout<<p1<<' '<<p2<<endl;
    int ret;
    cin>>ret;
    return ret;
}
int A[N];
int F(int start,int v1,int v2){
    int ret = 0;
    for(int bit = 0;bit<=30;++bit){
        int cur = 1<<bit;
        int a1 = (v1&cur)!=0,a2 = (v2&cur)!=0,a = (start&cur)!=0;
        for(int d = 0;d<2;++d){
            if ((d|a)==a1 && (d&a)==a2){
                ret+=d*cur;
                break;
            }
        }
    }
    return ret;
}
void solve(){
    int n,k;
    cin>>n>>k;
    int a11 = ask(1,2,0),a12 = ask(1,3,0),a13 = ask(1,2,1),a14 = ask(1,3,1),a15 = ask(2,3,1),a16 = ask(2,3,0);
    int a = 0;
    for(int bit = 0;bit<=30;++bit){
        int cur = 1<<bit;
        int a1 = (a11&cur)!=0,a2 = (a12&cur)!=0,a3 = (a13&cur)!=0,a4 = (a14&cur)!=0,a5 = (a15&cur)!=0,a6 = (a16&cur)!=0;
        for(int d = 0;d<2;++d){
            if ((d|a6)==(a1|a2) && (d&a5)==(a3&a4) && (d|a1)==a1 && (d|a2)==a2 && (d&a3)==a3 && (d&a4)==a4){
                a+=d*cur;
                break;
            }
        }
    }
    A[1] = a;
    A[2] = F(a,a11,a13);
    A[3] = F(a,a12,a14);
    for(int i = 4;i<=n;++i){
        int x = ask(1,i,0),y = ask(1,i,1);
        A[i] = F(A[1],x,y);
    }
    sort(A+1,A+1+n);
    cout<<"finish "<<A[k]<<endl;
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    //cin>>t;
    t = 1;
    while(t--)
        solve();
    return 0;
}