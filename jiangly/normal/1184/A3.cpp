#include<bits/stdc++.h>
using namespace std;
const int P=10000000;
int Pow(int a,int b,int p){
    int ans=1;
    while(b){
        if(b&1){
            ans=1ll*ans*a%p;
        }
        a=1ll*a*a%p;
        b>>=1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    string a,b;
    cin>>n>>m>>a>>b;
    vector<bool>is_prime(P,true);
    is_prime[1]=false;
    vector<int>prime;
    for(int i=2;i<P;++i){
        if(is_prime[i]){
            prime.push_back(i);
        }
        for(int p:prime){
            if(i*p>=P){
                break;
            }
            is_prime[i*p]=false;
            if(i%p==0){
                break;
            }
        }
    }
    mt19937 rnd(19260817);
    for(int d:prime){
        vector<int>x(d);
        for(int i=0;i<d;++i){
            for(int j=i;j<n;j+=d){
                x[i]+=a[j]-b[j];
            }
        }
        for(int p=(m+d-2)/d*d+1;p<P;p+=d){
            if((rnd()&32767)==0){
                break;
            }
            if(is_prime[p]){
                int r=rnd()%(p-1)+1;
                while(Pow(r,(p-1)/d,p)==1){
                    r=rnd()%(p-1)+1;
                }
                r=Pow(r,(p-1)/d,p);
                assert(Pow(r,d,p)==1);
                for(int i=0,j=1;i<d;++i,j=1ll*j*r%p){
                    if(j>=2&&j<=p-2){
                        int h=0;
                        for(int k=0,l=1;k<d;++k,l=1ll*l*j%p){
                            h=(h+1ll*l*x[k])%p;
                        }
                        if(h==0){
                            cout<<p<<' '<<j<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}