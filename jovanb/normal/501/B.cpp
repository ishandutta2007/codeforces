#include <bits/stdc++.h>
using namespace std;

unordered_map <string, string> mapa;
vector <string> imena;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    int n,i,m;
    string str,str1;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>str>>str1;
        m=0;
        for(string j : imena){
            if(mapa[j]==str){mapa[j]=str1;m=1;}
        }
        if(m==0){
            imena.push_back(str);
            mapa[str]=str1;
        }
    }
    cout<<imena.size()<<endl;
    for(string j: imena)cout<<j<<" "<<mapa[j]<<endl;
    return 0;
}