#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

const int MAXN = 2e5+10;
int main()
{
    int n,k;
    cin >> n>>k;
    char s[MAXN];
    cin >>s;
    stack<char> c;
    int cnt = 0;
    char ans[MAXN] ={0};
    int len = n;

    for(int i = 0 ; i < n ; i++)
    {
       // cout<<"s[i] ="<<s[i] <<" c.top() = "<<c.top()<<"len = "<<len<<"k = "<<k<<endl;
        if(!c.empty()&&s[i] == ')'&&c.top() == '('&&len>k)
        {
            ans[cnt-1] = 0;
            cnt--;
            c.pop();
            len-=2;

        }else{
            c.push(s[i]);
            ans[cnt] = s[i];
            cnt++;
        }
    }
    printf("%s",ans);
}