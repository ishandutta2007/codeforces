#include <bits/stdc++.h>

using namespace std;
unordered_map <string,long> br;
int main() {
    long n,i;
    string str;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>str;
        if(br[str]==0)cout<<"OK\n";
        else cout<<str<<br[str]<<endl;
        br[str]++;
    }
    return 0;
}