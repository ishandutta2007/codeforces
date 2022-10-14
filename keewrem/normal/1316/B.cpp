#include<bits/stdc++.h>
using namespace std;
int n,t,bb;
string s,best,curr;
bool smax(string &a, string &b){
    for(int i = 0; i < a.size();i++){
        if(a[i]<b[i])return true;
        if(b[i]<a[i])return false;
    }
    return false;
}
int main(){
    cin>>t;
    while(t--){
        cin >> n;
        cin >> s;
        best = s;
        curr = s;
        bb=1;
        //cout << n<<" "<<s;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < n-i+1; j++){
                curr[j]=s[j+i-1];
            }
            if(n%2==i%2){
                for(int j = 0; j < i-1; j++){
                    curr[n-j-1]=s[j];
                }
            }else{
                for(int j = 0; j < i-1; j++){
                    curr[j+n-i+1]=s[j];
                }
            }
            if(lexicographical_compare(curr.begin(),curr.end(),best.begin(),best.end())){
                bb = i; best = curr;
            }
        //    cout << "cc"<<curr <<"\n";
        }
        cout << best << "\n"<<bb << "\n";
    }
    return 0;
}