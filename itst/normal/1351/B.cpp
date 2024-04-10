#include<bits/stdc++.h>
using namespace std;

int main(){
int T;
for(cin>>T;T;--T){
int A,B,C,D; cin >> A>>B>>C>>D; if(A>B) swap(A,B); if(C>D) swap(C,D);
cout << (B == D && A + C == B ? "Yes" : "No") <<endl;
}
return 0;
}