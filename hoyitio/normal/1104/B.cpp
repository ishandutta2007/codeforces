#include<iostream>
#include<stack>

using namespace std;

int main()
{
    string s;
    stack<char> T;
    cin >> s;
    int cnt = 0;
    for(int i = 0 ; i < s.length() ; i++)
    {
       if(!T.empty() && s[i]==T.top())
       {
           T.pop();
           cnt++;
       }
       else{
            T.push(s[i]);
       }
    }
    if(cnt%2==0)
    {
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
    return 0;
}