#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> d(n);
        for(int i=0;i<n;++i){
            d[i]=s[i]-'0';
        }
        bool found=false;
        for(int x=0;x<=9;++x){
            bool ok=true;
            int lst=0;
            int rt=-1;
            int lf=n;
            for(int i=0;i<n;++i){
                if(d[i]<x){
                    if(d[i]<lst){
                        ok=false;
                        break;
                    }
                    lst=d[i];
                    rt=i;
                }
            }
            lst=9;
            for(int i=n-1;i>=0;--i){
                if(d[i]>x){
                    if(d[i]>lst){
                        ok=false;
                        break;
                    }
                    lst=d[i];
                    lf=i;
                }
            }
            for(int i=lf;i<=rt;++i){
                if(d[i]==x){
                    ok=false;
                    break;
                }
            }
            if(ok){
                found=true;
                for(int i=0;i<n;++i){
                    if(d[i]<x){
                        cout<<1;
                    }else if(d[i]>x){
                        cout<<2;
                    }else if(i>rt){
                        cout<<1;
                    }else{
                        cout<<2;
                    }
                }
                cout<<endl;
                break;
            }
        }
        if(!found){
            cout<<'-'<<endl;
        }
    }
    return 0;
}