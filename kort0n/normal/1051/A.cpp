#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int t;
    cin >> t;
    for(int time = 0; time < t; time++){
        string s;
        cin >> s;
        int moji[3];
        for(int i = 0; i < 3; i++){
            moji[i] = 0;
        }
        for(int i = 0; i < s.size(); i++){
            if(((char)'0' <= s[i]) && (s[i] <= (char)'9')){
                moji[0]++;
                //cout << t << " " << i << endl;
            }
            if(((int)'a' <= (int)(s[i])) && ((int)s[i] <= (int)'z')){
                moji[1]++;
                //cout << t << " " << i << endl;
            }
            if(((int)'A' <= (int)s[i]) && ((int)s[i] <= (int)'Z')){
                moji[2]++;
                //cout << t << " " << i << endl;
            }
        }
        if((moji[0] > 0) && (moji[1] > 0) && (moji[2] > 0)){
            cout << s << endl;
            continue;
        }
        if((moji[0] > 0) and (moji[1] == 0) and (moji[2] == 0)){
            cout << "Aa" << s.substr(2) << endl;
            continue;
        }
        if((moji[0] == 0) and (moji[1] > 0) and (moji[2] == 0)){
            cout << "1A" << s.substr(2) << endl;
            continue;
        }
        if((moji[0] == 0) and (moji[1] == 0) and (moji[2] > 0)){
            cout << "1a" << s.substr(2) << endl;
            continue;
        }
        if(moji[0] == 0){
            int i = 0;
            if(moji[1] > 1){
                while(true){
                    if(('a' <= s[i]) && (s[i] <= 'z')){
                        cout << 0;
                        i++;
                        break;
                    }
                    cout << s[i];
                    i++;
                    continue;
                }
                while(i < s.size()){
                    cout << s[i];
                    i++;
                    continue;
                }
                cout << endl;
                continue;
            }
            while(true){
                if(('A' <= s[i]) && (s[i] <= 'Z')){
                    cout << 0;
                    i++;
                    break;
                }
                cout << s[i];
                i++;
                continue;
            }
            while(i < s.size()){
                cout << s[i];
                i++;
                continue;
            }
            cout << endl;
            continue;
        }
        if(moji[1] == 0){
            int i = 0;
            if(moji[0] > 1){
                while(true){
                    if(((char)'0' <= s[i]) && (s[i] <= (char)'9')){
                        cout << "a";
                        i++;
                        break;
                    }
                    cout << s[i];
                    i++;
                    continue;
                }
                while(i < s.size()){
                    cout << s[i];
                    i++;
                    continue;
                }
                cout << endl;
                continue;
            }
            while(true){
                if(('A' <= s[i]) && (s[i] <= 'Z')){
                    cout << "a";
                    i++;
                    break;
                }
                cout << s[i];
                i++;
                continue;
            }
            while(i < s.size()){
                cout << s[i];
                i++;
                continue;
            }
            cout << endl;
            continue;
        }
        if(moji[2] == 0){
            int i = 0;
            if(moji[1] > 1){
                while(true){
                    if(('a' <= s[i]) && (s[i] <= 'z')){
                        cout << "A";
                        i++;
                        break;
                    }
                    cout << s[i];
                    i++;
                    continue;
                }
                while(i < s.size()){
                    cout << s[i];
                    i++;
                    continue;
                }
                cout << endl;
                continue;
            }
            while(true){
                if(((char)'0' <= s[i]) && (s[i] <= (char)'9')){
                    cout << "A";
                    i++;
                    break;
                }
                cout << s[i];
                i++;
                continue;
            }
            while(i < s.size()){
                cout << s[i];
                i++;
                continue;
            }
            cout << endl;
            continue;
        }
    }
    return 0;
}