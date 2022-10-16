#include <iostream>

using namespace std;

string s;

bool pal(string &a)
{
    int k=a.size();
    for(int i=0; i<a.size(); i++)
    {
        if(a[k-i-1]=='.')
            a[k-i-1]=a[i];
        if(a[i]=='.')
            a[i]=a[k-i-1];
        if(a[i]!=a[k-i-1])
            return false;
    }
    return true;
}

int main()
{
    cin>>s;

    for(int i=0; i<=s.size(); i++)
    {
        string cs=s;
        cs.insert(i,".");
        if(pal(cs))
        {
            cout<<cs;
            return 0;
        }
    }
    /*
    string cs=s;
    cs+=cs[0];
    if(pal(cs))
    {
        cout<<cs;
        return 0;
    }*/
    cout<<"NA";
    return 0;

}