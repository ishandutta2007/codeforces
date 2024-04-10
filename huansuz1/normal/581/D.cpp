#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
int x1,y1,x2,y2,x3,y3,a,b,c,a1,b1,c1;


int main()
{   
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    if (x1==x2 && x1==x3 && y1+y2+y3==x1) {
        cout<<x1<<endl;
        for ( int i=0; i<y1; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"A";          
            cout<<endl;     
        }
        for ( int i=0; i<y2; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"B";          
            cout<<endl;     
        }
        for ( int i=0; i<y3; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }
    if (x1==y2 && x1==x3 && y1+x2+y3==x1) {
        cout<<x1<<endl;
        for ( int i=0; i<y1; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"A";          
            cout<<endl;     
        }
        for ( int i=0; i<x2; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"B";          
            cout<<endl;     
        }
        for ( int i=0; i<y3; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }
    if (x1==x2 && x1==y3 && y1+y2+x3==x1) {
        cout<<x1<<endl;
        for ( int i=0; i<y1; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"A";          
            cout<<endl;     
        }
        for ( int i=0; i<y2; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"B";          
            cout<<endl;     
        }
        for ( int i=0; i<x3; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }
    if (x1==y2 && x1==y3 && y1+x2+x3==x1) {
        cout<<x1<<endl;
        for ( int i=0; i<y1; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"A";          
            cout<<endl;     
        }
        for ( int i=0; i<x2; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"B";          
            cout<<endl;     
        }
        for ( int i=0; i<x3; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }


 

    if (y1==x2 && y1==x3 && x1+y2+y3==y1) {
        cout<<y1<<endl;
        for ( int i=0; i<x1; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"A";          
            cout<<endl;     
        }
        for ( int i=0; i<y2; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"B";          
            cout<<endl;     
        }
        for ( int i=0; i<y3; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }
    if (y1==y2 && y1==x3 && x1+x2+y3==y1) {
        cout<<y1<<endl;
        for ( int i=0; i<x1; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"A";          
            cout<<endl;     
        }
        for ( int i=0; i<x2; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"B";          
            cout<<endl;     
        }
        for ( int i=0; i<y3; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }
    if (y1==x2 && y1==y3 && x1+y2+x3==y1) {
        cout<<y1<<endl;
        for ( int i=0; i<x1; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"A";          
            cout<<endl;     
        }
        for ( int i=0; i<y2; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"B";          
            cout<<endl;     
        }
        for ( int i=0; i<x3; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }
    if (y1==y2 && y1==y3 && x1+x2+x3==y1) {
        cout<<y1<<endl;
        for ( int i=0; i<x1; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"A";          
            cout<<endl;     
        }
        for ( int i=0; i<x2; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"B";          
            cout<<endl;     
        }
        for ( int i=0; i<x3; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }


    /*----------------------------------------------*/
    if (x1==x2+x3 && y3==y2 && y1+y2==x1) {
        cout<<x1<<endl;
        for ( int i=0; i<y1; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"A";          
            cout<<endl;     
        }
        for ( int i=0; i<y2; i++ ) {
            for (int j=0; j<x2; j++)
                cout<<"B";          
            for (int j=0; j<x3; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }
    if (x1==y2+x3 && y3==x2 && y1+x2==x1) {
        cout<<x1<<endl;
        for ( int i=0; i<y1; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"A";          
            cout<<endl;     
        }
        for ( int i=0; i<y3; i++ ) {
            for (int j=0; j<y2; j++)
                cout<<"B";          
            for (int j=0; j<x3; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }   
    if (x1==x2+y3 && x3==y2 && y1+y2==x1) {
        cout<<x1<<endl;
        for ( int i=0; i<y1; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"A";          
            cout<<endl;     
        }
        for ( int i=0; i<y2; i++ ) {
            for (int j=0; j<x2; j++)
                cout<<"B";          
            for (int j=0; j<y3; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }   
    if (x1==y2+y3 && x3==x2 && y1+x2==x1) {
        cout<<x1<<endl;
        for ( int i=0; i<y1; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"A";          
            cout<<endl;     
        }
        for ( int i=0; i<x2; i++ ) {
            for (int j=0; j<y2; j++)
                cout<<"B";          
            for (int j=0; j<y3; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }   
    

    if (y1==x2+x3 && y3==y2 && x1+y2==y1) {
        cout<<y1<<endl;
        for ( int i=0; i<x1; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"A";          
            cout<<endl;     
        }
        for ( int i=0; i<y2; i++ ) {
            for (int j=0; j<x2; j++)
                cout<<"B";          
            for (int j=0; j<x3; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }
    if (y1==y2+x3 && y3==x2 && x1+x2==y1) {
        cout<<y1<<endl;
        for ( int i=0; i<x1; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"A";          
            cout<<endl;     
        }
        for ( int i=0; i<y3; i++ ) {
            for (int j=0; j<y2; j++)
                cout<<"B";          
            for (int j=0; j<x3; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }   
    if (y1==x2+y3 && x3==y2 && x1+y2==y1) {
        cout<<y1<<endl;
        for ( int i=0; i<x1; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"A";          
            cout<<endl;     
        }
        for ( int i=0; i<y2; i++ ) {
            for (int j=0; j<x2; j++)
                cout<<"B";          
            for (int j=0; j<y3; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }   
    if (y1==y2+y3 && x3==x2 && x1+x2==y1) {
        cout<<y1<<endl;
        for ( int i=0; i<x1; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"A";          
            cout<<endl;     
        }
        for ( int i=0; i<x2; i++ ) {
            for (int j=0; j<y2; j++)
                cout<<"B";          
            for (int j=0; j<y3; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }   
    
    
    /*----------------------------------------------*/
    swap (x1,x2); swap(y1,y2);
    if (x1==x2+x3 && y3==y2 && y1+y2==x1) {
        cout<<x1<<endl;
        for ( int i=0; i<y1; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"B";          
            cout<<endl;     
        }
        for ( int i=0; i<y2; i++ ) {
            for (int j=0; j<x2; j++)
                cout<<"A";          
            for (int j=0; j<x3; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }
    if (x1==y2+x3 && y3==x2 && y1+x2==x1) {
        cout<<x1<<endl;
        for ( int i=0; i<y1; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"B";          
            cout<<endl;     
        }
        for ( int i=0; i<y3; i++ ) {
            for (int j=0; j<y2; j++)
                cout<<"A";          
            for (int j=0; j<x3; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }   
    if (x1==x2+y3 && x3==y2 && y1+y2==x1) {
        cout<<x1<<endl;
        for ( int i=0; i<y1; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"B";          
            cout<<endl;     
        }
        for ( int i=0; i<y2; i++ ) {
            for (int j=0; j<x2; j++)
                cout<<"A";          
            for (int j=0; j<y3; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }   
    if (x1==y2+y3 && x3==x2 && y1+x2==x1) {
        cout<<x1<<endl;
        for ( int i=0; i<y1; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"B";          
            cout<<endl;     
        }
        for ( int i=0; i<x2; i++ ) {
            for (int j=0; j<y2; j++)
                cout<<"A";          
            for (int j=0; j<y3; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }   
    

    if (y1==x2+x3 && y3==y2 && x1+y2==y1) {
        cout<<y1<<endl;
        for ( int i=0; i<x1; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"B";          
            cout<<endl;     
        }
        for ( int i=0; i<y2; i++ ) {
            for (int j=0; j<x2; j++)
                cout<<"A";          
            for (int j=0; j<x3; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }
    if (y1==y2+x3 && y3==x2 && x1+x2==y1) {
        cout<<y1<<endl;
        for ( int i=0; i<x1; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"B";          
            cout<<endl;     
        }
        for ( int i=0; i<x2; i++ ) {
            for (int j=0; j<y2; j++)
                cout<<"A";          
            for (int j=0; j<x3; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }   
    if (y1==x2+y3 && x3==y2 && x1+y2==y1) {
        cout<<y1<<endl;
        for ( int i=0; i<x1; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"B";          
            cout<<endl;     
        }
        for ( int i=0; i<y2; i++ ) {
            for (int j=0; j<x2; j++)
                cout<<"A";          
            for (int j=0; j<y3; j++)
                cout<<"C";          
            cout<<endl;     
        }
        return 0;
    }   
    if (y1==y2+y3 && x3==x2 && x1+x2==y1) {
        cout<<y1<<endl;
        for ( int i=0; i<x1; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"B";          
            cout<<endl;     
        }
        for ( int i=0; i<x2; i++ ) {
            for (int j=0; j<y2; j++)
                cout<<"A";          
            for (int j=0; j<y3; j++)
                cout<<"C";          
            cout<<endl;     
        }
    
        return 0;
    }
    
    /*----------------------------------------------*/
    swap (x1,x3); swap(y1,y3);
    if (x1==x2+x3 && y3==y2 && y1+y2==x1) {
        cout<<x1<<endl;
        for ( int i=0; i<y1; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"C";          
            cout<<endl;     
        }
        for ( int i=0; i<y2; i++ ) {
            for (int j=0; j<x2; j++)
                cout<<"A";          
            for (int j=0; j<x3; j++)
                cout<<"B";          
            cout<<endl;     
        }
        return 0;
    }
    if (x1==y2+x3 && y3==x2 && y1+x2==x1) {
        cout<<x1<<endl;
        for ( int i=0; i<y1; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"C";          
            cout<<endl;     
        }
        for ( int i=0; i<y3; i++ ) {
            for (int j=0; j<y2; j++)
                cout<<"A";          
            for (int j=0; j<x3; j++)
                cout<<"B";          
            cout<<endl;     
        }
        return 0;
    }   
    if (x1==x2+y3 && x3==y2 && y1+y2==x1) {
        cout<<x1<<endl;
        for ( int i=0; i<y1; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"C";          
            cout<<endl;     
        }
        for ( int i=0; i<y2; i++ ) {
            for (int j=0; j<x2; j++)
                cout<<"A";          
            for (int j=0; j<y3; j++)
                cout<<"B";          
            cout<<endl;     
        }
        return 0;
    }   
    if (x1==y2+y3 && x3==x2 && y1+x2==x1) {
        cout<<x1<<endl;
        for ( int i=0; i<y1; i++ ) {
            for (int j=0; j<x1; j++)
                cout<<"C";          
            cout<<endl;     
        }
        for ( int i=0; i<x2; i++ ) {
            for (int j=0; j<y2; j++)
                cout<<"A";          
            for (int j=0; j<y3; j++)
                cout<<"B";          
            cout<<endl;     
        }
        return 0;
    }   
    

    if (y1==x2+x3 && y3==y2 && x1+y2==y1) {
        cout<<y1<<endl;
        for ( int i=0; i<x1; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"C";          
            cout<<endl;     
        }
        for ( int i=0; i<y2; i++ ) {
            for (int j=0; j<x2; j++)
                cout<<"A";          
            for (int j=0; j<x3; j++)
                cout<<"B";          
            cout<<endl;     
        }
        return 0;
    }
    if (y1==y2+x3 && y3==x2 && x1+x2==y1) {
        cout<<y1<<endl;
        for ( int i=0; i<x1; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"C";          
            cout<<endl;     
        }
        for ( int i=0; i<x2; i++ ) {
            for (int j=0; j<y2; j++)
                cout<<"A";          
            for (int j=0; j<x3; j++)
                cout<<"B";          
            cout<<endl;     
        }
        return 0;
    }   
    if (y1==x2+y3 && x3==y2 && x1+y2==y1) {
        cout<<y1<<endl;
        for ( int i=0; i<x1; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"C";          
            cout<<endl;     
        }
        for ( int i=0; i<y2; i++ ) {
            for (int j=0; j<x2; j++)
                cout<<"A";          
            for (int j=0; j<y3; j++)
                cout<<"B";          
            cout<<endl;     
        }
        return 0;
    }   
    if (y1==y2+y3 && x3==x2 && x1+x2==y1) {
        cout<<y1<<endl;
        for ( int i=0; i<x1; i++ ) {
            for (int j=0; j<y1; j++)
                cout<<"C";          
            cout<<endl;     
        }
        for ( int i=0; i<x2; i++ ) {
            for (int j=0; j<y2; j++)
                cout<<"A";          
            for (int j=0; j<y3; j++)
                cout<<"B";          
            cout<<endl;     
        }
        return 0;
    }
    

    cout<<-1;
    
    return 0;
}