#include <iostream>

using namespace std;
int n, v[102], sol;

char s[3002];

int main()
{
int a, b, k;
cin>>n;
cin>>s;
a=0;
b=0;
k=0;

for(int i=0;i<n;i++)
{
    if(s[i]=='.') k++;
//    {
//        //if(a==0)
//        k++;
//        //if(a==-1)
//        //{
//          //  if(k%2==1)
//            //    sol++;
//            //k=0;
//        //}
//    }

    if(s[i]=='L')
    {
        if(a==0)
            k=0, a=0;
        if(a==-1)
        {
            if(k%2==1)
                 sol++;
            k=0;
            a=0;
        }
    }
    if(s[i]=='R')
    {
    if(a==0)
        sol+=k, k=0;
    if(a==-1) k++;
    a=-1;
    }


}
if(a==0)
sol+=k;
cout<<sol;

}