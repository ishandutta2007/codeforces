#include <bits/stdc++.h>

using namespace std;

int main(){
        int n;
        string s;
        cin>>n>>s;
        if (n==1){
                cout<<"Yes";
                return 0;
        }
        for(char i='a';i<='z';i++)
                if (count(s.begin(),s.end(),i)>1){
                        cout<<"Yes";
                        return 0;
                }
        cout<<"No";
}