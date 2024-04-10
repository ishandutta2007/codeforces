#include <iostream>

int main()
{
    int a,b;
    std::string S;
    std::cin>>S;
    if(S=="monday") a = 1;
    if(S=="tuesday") a = 2;
    if(S=="wednesday") a = 3;
    if(S=="thursday") a = 4;
    if(S=="friday") a = 5;
    if(S=="saturday") a = 6;
    if(S=="sunday") a = 7;

    std::cin>>S;
    if(S=="monday") b = 1;
    if(S=="tuesday") b = 2;
    if(S=="wednesday") b = 3;
    if(S=="thursday") b = 4;
    if(S=="friday") b = 5;
    if(S=="saturday") b = 6;
    if(S=="sunday") b = 7;
    if(b-a==0) std::cout<<"YES";
    else if(b-a==2||b-a==-5) std::cout<<"YES";
    else if(b-a==3||b-a==-4) std::cout<<"YES";
    else std::cout<<"NO";
}