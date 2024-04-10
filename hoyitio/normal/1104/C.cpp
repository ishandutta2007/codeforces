#include<iostream>

using namespace std;

bool G[5][5];
void fun(char s)
{
    int tr,tc;
    for(int r = 0 ; r < 4 ; r++)
    {
        for(int c = 0 ; c < 4 ; c++)
        {
            if(s=='0')
            {
                bool flag = false;
                if(r!=3 && !G[r][c] && !G[r+1][c])
                {
                    tr = r;
                    tc = c;
                    bool temp = true;
                    for(int t = 0 ; t < 4 ; t++)
                    {
                        if(t!=r&&t!=r+1)
                        {
                            if(!G[t][c])
                            {
                                temp = false;
                            }
                        }
                    }
                    if(temp)
                    {
                        flag = true;
                    }
                }
                if(flag)
                {
                    for(int t = 0 ; t < 4 ; t++)
                    {
                        G[t][c]= false;
                    }
                    cout<<r+1<<" "<<c+1<<endl;
                    return;
                }
            }
            else
            {
                bool flag = false;
                if(c!=3 && !G[r][c] && !G[r][c+1])
                {
                    tr = r;
                    tc = c;
                    bool temp = true;
                    for(int t = 0 ; t < 4 ; t++)
                    {
                        if(t!=c&&t!=c+1)
                        {
                            if(!G[r][t])
                            {
                                temp = false;
                            }
                        }
                    }
                    if(temp)
                    {
                        flag = true;
                    }
                }
                if(flag)
                {
                    for(int t = 0 ; t < 4 ; t++)
                    {
                        G[r][t]= false;
                    }
                    cout<<r+1<<" "<<c+1<<endl;
                    return;
                }
            }
        }
    }
    if(s=='0')
    {
        G[tr][tc] = true;
        G[tr+1][tc] = true;
        cout<<tr+1<<" "<<tc+1<<endl;
    }else{
        G[tr][tc] = true;
        G[tr][tc+1] = true;
        cout<<tr+1<<" "<<tc+1<<endl;
    }
}
int main()
{
    string s;
    cin >> s;
    for(int i = 0 ; i < s.length() ; i++)
    {
        fun(s[i]);
    }
    return 0;
}