#include <bits/stdc++.h>
using namespace std;
int sas[100000];
int main(){
    int T,N,mx,mn,mm;
    cin>>T;
    while(T--){
        cin >> N;
        mx =0; mm = 0;
        mn = 1000000010;
        for(int i = 0; i <N; i++)cin>>sas[i];
        for(int i =0;i <N; i++)if(sas[i]!=-1){
            if(i>0 && sas[i-1]!=-1){
                mm = max(mm,abs(sas[i]-sas[i-1]));
            }else if(i>0){
                mx=max(sas[i],mx); mn=min(sas[i],mn);
            }
            if(i<N-1 && sas[i+1]!=-1){
                mm = max(mm,abs(sas[i]-sas[i+1]));
            }else if(i<N-1){
                mx=max(sas[i],mx); mn=min(sas[i],mn);
            }
        }
        cout << max((mx-mn+1)/2,mm)<<" " <<(mx+mn)/2<<"\n";
    }
    return 0;
}