#include<bits/stdc++.h>
using namespace std;
string str;
int length,num;
int main()
{
    cin>>num>>str;
    num=0;
    if(str.length()%2==0)
    {
    	while(length<=2&&num<str.length()-1)
 	    {
    		cout<<str[num];
    		length++;
    		num++;
    		if(length==2)
    		{
    			cout<<"-";
    			length=0;
			}
		}
		cout<<str[str.length()-1];
	}
    else
    {
    	while(length<=2&&num<str.length()-3)
 	    {
    		cout<<str[num];
    		length++;
    		num++;
    		if(length==2)
    		{
    			cout<<"-";
    			length=0;
			}
		}
		cout<<str[str.length()-3]<<str[str.length()-2]<<str[str.length()-1];
	}
}