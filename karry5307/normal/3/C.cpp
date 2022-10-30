#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll win[8][3]={{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}};
ll first,second;
bool fwin,swin;
char ch[3][3];
inline string link(ll tag)
{
    string res;
    for(register int i=0;i<3;i++)
    {
        res+=ch[(win[tag][i]-1)/3][(win[tag][i]-1)%3];
    }
    return res;
}
int main()
{
	//freopen("testdata.in","r",stdin);
	//freopen("testdata.out","w",stdout);
    for(register int i=0;i<3;i++)
    {
        for(register int j=0;j<3;j++)
        {
            cin>>ch[i][j];
            if(ch[i][j]=='X')
            {
                first++;
            }
            if(ch[i][j]=='0')
            {
                second++;
            }
        }
    }
    for(register int i=0;i<8;i++)
    {
        if(link(i)=="XXX")
        {
            fwin=1;
        }
        if(link(i)=="000")
        {
            swin=1;
        }
    }
    if((fwin&&swin)||(fwin&&second!=first-1)||(swin&&first!=second)||(first!=second&&first!=second+1))
    {
        cout<<"illegal"<<endl;
        return 0;
    }
    if(fwin||swin)
    {
        if(fwin)
        {
            cout<<"the first player won"<<endl;
        }
        else
        {
            cout<<"the second player won"<<endl;
        }
    }
    else
    {
        if(first+second==9)
        {
            cout<<"draw"<<endl;
        }
        else
        {
            if(first==second+1)
            {
                cout<<"second"<<endl;
            }
            if(first==second)
            {
                cout<<"first"<<endl;
            }
        }
    }
}