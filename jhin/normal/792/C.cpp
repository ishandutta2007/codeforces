#include <bits/stdc++.h>

using namespace std;
vector<int>a;string s;int n,sum,z,p[2],j;bool yes;
void solve(int x)
{
        for(int i=n-1;i>=0;i--)
        {
            if(i==0&&a[i]%3==x){yes=true;break;}
            if(a[i]%3==x){s.erase(s.begin()+i); cout<<s;return ;}
        }
       for(int i=n-1;i>=0;i--)
       if(a[i]%3!=x&&a[i]%3!=0&&j!=2)p[j++]=i;
       if(yes){z=1;while(!a[z]&&z<n-1)z++;if(j<2||z<=2){s.erase(s.begin(),s.begin()+z);cout<<s;return ;}}
       if(j==2){s.erase(s.begin()+p[0]);s.erase(s.begin()+p[1]);a.erase(a.begin()+p[0]);a.erase(a.begin()+p[1]);
                 z=0;if(!s.empty()){while(!a[z]&&z<n-3)z++;if(z)s.erase(s.begin(),s.begin()+z);
                    cout<<s;return ;}
                }
       cout<<-1;return;
}

int main()
{
cin>>s;n=s.size();
for(int i=0;i<n;i++){int k=s[i]-48;a.push_back(k);sum+=a[i];}
if(sum%3==0)cout<<s;
else if(n==1&&s[0]%3!=0)cout<<-1;
else solve(sum%3);

    return 0;
}