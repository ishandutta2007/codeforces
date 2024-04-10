#include <bits/stdc++.h>
using namespace std;
int main(){
    int T,N,res; string a,b,c;
    cin>>T;
    while(T--){
        cin >> a>>b>>c;
        res= 0;
        N = a.size();
        for(int i = 0; i < N; i++){
            if(a[i]==c[i]||c[i]==b[i])res++;
        }
        if(res==N)cout<<"YES";else cout << "NO";
        cout << "\n";
    }
    return 0;
}