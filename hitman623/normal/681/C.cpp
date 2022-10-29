#include <bits/stdc++.h>
#define pb push_back

using namespace std;

long long n,i,x,num[1000007]={0},l=0;
priority_queue < long long , vector<long long >,std::greater<long long> > st;
char s[1000],a[1000007];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>s;
        if(s[0]!='r')
            cin>>x;
        if(s[0]=='r')
        {
            if(st.empty())
                {a[l++]='i';
                num[l-1]=1;
                st.push(1);}
            a[l++]='r';
            st.pop();
        }
        if(s[0]=='i')
        {
            a[l++]='i';
            num[l-1]=x;
            st.push(x);
        }
        if(s[0]=='g')
            {
                if(st.empty()==0)
                    while(st.top()<x)
                    {
                        a[l++]='r';
                        st.pop();
                        if(st.empty()) break;
                    }
                    if(st.empty())
                    {a[l++]='i';num[l-1]=x;st.push(x);}
                    else if(st.top()!=x)
                    {a[l++]='i';num[l-1]=x;st.push(x);}
                    a[l++]='g';num[l-1]=x;
            }
    }
    cout<<l<<endl;
    for(i=0;i<l;++i)
        if(a[i]=='r')
        cout<<"removeMin"<<endl;
        else if(a[i]=='g')
        cout<<"getMin "<<num[i]<<endl;
        else cout<<"insert "<<num[i]<<endl;
    return 0;
}