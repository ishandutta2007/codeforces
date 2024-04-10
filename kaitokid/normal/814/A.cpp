#include <iostream>

using namespace std;

int main()
{bool bl=false;
bool bl2=false;
   int n,y=0,s=0,x,m,down=0,up=INT_MAX;
   cin>>n>>m;
   if(m>1){
   for(int i=0;i<n;i++)cin>>x;
   for(int i=0;i<m;i++)cin>>x;
    cout<<"Yes";
    return 0;
   }
    for(int i=0;i<n;i++){

        cin>>x;
        s=max(s,x);
      if(bl2==true){up=x;bl2=false;}
        if(x!=0&&x<s){bl=true;}
    if(x==0){down=y;bl2=true;}
    y=x;
    }

    cin>>x;
   // cout<<down<<" "<<up<<endl;
    if(x<down||x>up){bl=true;}
    if(bl==true){cout<<"Yes";}else{cout<<"No";}
    return 0;
}