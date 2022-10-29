#include<bits/stdc++.h>

using namespace std;

long long work(long long x){
    int n = 0;
    string s = "";
    while(x){
        s = (char)('0' + x%2) + s;
        x /= 2;
        n++;
    }
//  cout<<x<<endl;
//  cout<<n<<endl;
    
    long long ans = 0;
    for(int i = 1; i < n; i++)
        ans += (i-1);
    ans++;
    for(int i = 1; i < n; i++){
        string ss = "";
        for(int j = 0; j < n; j++)
            ss = ss + (char)('0' + (i != j));
//      cout<<s<<' '<<ss<<endl;
        if (s >= ss)
            ans++;
    }
    return ans;
}

int main(){
    long long a, b;
    cin>>a>>b;
    cout<<work(b) - work(a-1)<<endl;
    return 0;
}