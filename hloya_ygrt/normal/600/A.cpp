#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>


using namespace std;
  int areNums[100000]={0};
int main()
{

    string s;
    string a,b;

    cin>>s;
    s.push_back(',');
    int j=0,k=0;

    for (int i=0;i<s.length();i++)
    {


        while (s[j]!=','&&s[j]!=';')
            j++;
        int i1=i;
        j++;
        int isanum=1 , leadnul=0;
        while (i<=j-2)
        {
            if (!isanum)
            {
                i++;
                continue;
            }

            if (!leadnul&&s[i]=='0')
            {
                isanum=0;
            }

            if (isanum&&s[i]>='0'&&s[i]<='9')
            {
                leadnul=1;
            } else
            isanum=0;

            i++;
        }

        if (isanum||(i1==j-2&&s[i1]=='0'))
        {
            areNums[k]=1;
        }
        if (j-1==i1)
            areNums[k]=0;
        k++;
        i=j-1;

    }
   j=0;

    for (int i=0;i<s.length();i++)
    {
        if (areNums[j])
        {
            while (s[i]!=';'&&s[i]!=',')
            {
                a.push_back(s[i]);
                i++;
            }
            a.push_back(',');
        }
        else
        {
            while (s[i]!=';'&&s[i]!=',')
            {
                b.push_back(s[i]);
                i++;
            }
            b.push_back(',');
        }
        j++;
    }
    if (a.size()==0)
        cout<<'-'<<endl;
    else
    {
        cout<<'"';
        for (int i=0;i<a.size()-1;i++)
            cout<<a[i];
        cout<<'"'<<endl;
    }

       if (b.size()==0)
        cout<<'-'<<endl;
    else
    {
        cout<<'"';
        for (int i=0;i<b.size()-1;i++)
            cout<<b[i];
        cout<<'"'<<endl;
    }
//while (1){}

    return 0;
}