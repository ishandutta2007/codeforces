
#include <iostream>
#include <string>

using namespace std;

int main()
{
   int n,k,summ=0,save1, v;
   cin>>n;
   cin>>k;
   int time=240-k;
   for(int i=1; summ<=time; i++)
   {
       summ=summ+i*5;
       save1=i;
       if(i>n)
         break;
       
   }
   cout<<save1-1;
   
}