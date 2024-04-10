#include <iostream>
#include <string>

using namespace std;

int main() {
    int num, sum=0;
    string poly;
    cin >> num;
    for(int a=0; a<num; a++) {
        cin >> poly;
        if(poly=="Tetrahedron")
            sum+=4;
        if(poly=="Cube")
            sum+=6;
        if(poly=="Octahedron")
            sum+=8;
        if(poly=="Icosahedron")
            sum+=20;
        if(poly=="Dodecahedron")
            sum+=12;
    }
    cout << sum;
}