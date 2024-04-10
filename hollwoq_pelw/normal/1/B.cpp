#include <iostream>
#include <ctype.h>
using namespace std;
void type2(string a){
	int col = 0,row = 0;
	for (unsigned int i = 0; i < a.size(); i++){
		if (isalpha(a[i])){
			col = col*26+(int)(a[i]-64);
		}else {
			row = row*10+(int)(a[i]-48);
		}
	}
	cout << 'R' << row << 'C' << col << endl;
	return ;
}
void type1(int n, int m) { 
    string str = "";
    while (n>0) { 
        int rem = n%26; 
        if (rem==0) { 
            str += 'Z'; 
            n = (n/26)-1; 
        } else { 
            str += (rem-1) + 'A'; 
            n = n/26; 
        } 
    } 
    int k = str.size();
    for (int i = k-1; i >= 0; i--){
    	cout << str[i];
	}
    cout << m << endl; 
    return; 
} 
int main(){
    int n;
    string a;
    cin >> n;
    while(n){
        n--;
        cin >> a;
        int row = 0;
        int col = 0;
        string s = "";
        bool t1 = false;
        
        unsigned int pos1,pos2;
        for (unsigned int i = 0; i < a.size(); i++){
            // check if type1 "R..C.."
            if (a[0] == 'R' && a[i] == 'C' && !isalpha(a[i-1])){
                // find pos of char 'R' and 'C'
                t1 = true;
                pos1 = 0;
                pos2 = i;
                break;
            }
        }
        if (t1){
            for (unsigned int i = 0; i < a.size(); i++){
                if (pos1 < i && i < pos2){
                    // val of row
                    row = row*10+(int)(a[i]-48);
                }else if (pos2 < i){
                    // val of col
                    col = col*10+(int)(a[i]-48);
                }
            }
            type1(col, row);
        }else {
            type2(a);
        }
 
    }
}