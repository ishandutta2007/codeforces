#include <iostream>
#include <string>

long long helper( long long a, long long b)
{
    return a/b+(a%b!=0?1:0);
}

int main()
{
  long long a,b,c;
  std::cin>>a>>b>>c;
  long long ans = helper(a,c)*helper(b,c);
  std::cout<<ans<<std::endl;
}