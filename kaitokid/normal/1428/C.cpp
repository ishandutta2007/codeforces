#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//int dp[200009][3];
int main()
{
    ios::sync_with_stdio(0);
    int t,n;
    cin>>t;
string s;
    while(t--)
    {
        cin>>s;
        n=s.size();
        stack<char> st;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty()){st.push(s[i]);continue;}
            char z=st.top();
            if(z=='B'&&s[i]=='A'){st.pop();continue;}
            st.push(s[i]);
        }
        int d[2]={0,0};
        while(!st.empty()){char z=st.top();st.pop();d[z-'A']++;}
        cout<<d[0]+(d[1]%2)<<endl;
    }
    return 0;
}