#include <bits/stdc++.h>

using namespace std;

int main(){
        int n,m;
        string s1,s2;
        cin>>n>>m>>s1>>s2;
        if (count(s1.begin(),s1.end(),'*')==0){
            cout<<((s1==s2)?"YES":"NO");
            return 0;
        }
        if (n>m+1){
                cout<<"NO";
                return 0;
        }
        for(int i=0;s1[i]!='*';i++){
                if (s1[i]!=s2[i]){
                        cout<<"NO";
                        return 0;
                }
        }
        for(int i=1;s1[n-i]!='*';i++) {
                if (s1[n-i]!=s2[m-i]){
                        cout<<"NO";
                        return 0;
                }
        }
        cout<<"YES";
}