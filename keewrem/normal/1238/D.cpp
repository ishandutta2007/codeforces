#include<bits/stdc++.h>
using namespace std;
int N,i;
int kekl[300000], kekr[300000];
int main(){
    scanf("%d",&N);
    int q = 1;
    string sos;
    cin>>sos;
    for(i = 1; i < N; i++){
        if(sos[i]!=sos[i-1]){
            kekl[i]=q;
            q = 0;
        }
        q++;
    }
    q = 1;
    for(i = N-2; i >= 0; i--){
        if(sos[i]!=sos[i+1]){
            kekr[i]=q;
            q = 0;
        }
        q++;
    }
    //for(i = 0; i < N; i++)cout << kekl[i]<<" "<<kekr[i]<<"\n";
    long long res = (long long)(N+1)*N/2;
    for(int i =0; i < N; i++)res-=kekr[i]+kekl[i]+1;
    for(int i = 1; i < N;i++)if(sos[i]!=sos[i-1])res++;
    cout<<res;
    return 0;
}