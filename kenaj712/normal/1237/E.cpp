#include<bits/stdc++.h>
using namespace std;
bool rek(int a,int b,int c)
{
    if(a==b)
    {
        if(a%2==c)
            return true;
        else
            return false;
    }
    if(b-a==1)
    {
        if(b%2==c)
            return true;
        else
            return false;
    }
    bool xd=true;
    int cand1,cand2;
    if((b-a+1)%2==1)
    {
        cand1=(a+b)/2;
        if(cand1%2!=c)
            return false;
        return (xd&rek(a,cand1-1,(cand1+1)%2)&rek(cand1+1,b,cand1%2));
    }
    else
    {
        cand1=(a+b)/2;
        cand2=cand1+1;
        if(cand1%2!=c)
            cand1=cand2;
        return (xd&rek(a,cand1-1,(cand1+1)%2)&rek(cand1+1,b,cand1%2));
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a;
	cin>>a;
    if(a%2==1)
    {
        cout<<rek(1,a,((a+1)/2)%2);
    }
    else
    {
        int licz1=rek(1,a,0);
        if(rek(1,a,1)==true)
            licz1++;
        cout<<licz1;
    }
	return 0;
}