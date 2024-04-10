#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

deque <int> dq;
int n,k;
string s;
int a[N];
int main(){
        cin>>n>>k>>s;
        string ans;
        k>>=1;
        int rem=0;
        for(auto ch:s){
                if (ch=='('){
                        if (k){
                                ans.push_back('(');
                                rem++,k--;
                        }
                }else{
                        if (rem){
                                ans.push_back(')');
                                rem--;
                        }
                }
        }
        cout<<ans;

}