#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    deque<int> q;

    while( a && b ){
        q.push_back(0);
        q.push_back(1);
        a--, b--;
    }

    while( c && d ){
        q.push_back(2);
        q.push_back(3);
        c--, d--;
    }

    if( a && ( q.empty() || q.back() == 1 ) ){
        a--;
        q.push_back(0);
    }

    if( d && ( q.empty() || q.front() == 2 ) ){
        d--;
        q.push_front(3);
    }

    while( c || b ){
        if( b && b >= c && ( q.empty() || ( q.front() == 0 || q.front() == 2 || q.back() == 0 || q.back() == 2 ) ) ){
            if( ( q.empty() || q.front() == 0 || q.front() == 2 ) ){
                q.push_front(1);
                b--;
                continue;
            }
            if( ( q.empty() || ( q.back() == 0 || q.back() == 2 ) ) ){
                q.push_back(1);
                b--;
                continue;
            }
            break;
        }
        else if( c ) {
            if( ( q.empty() || ( q.front() == 1 || q.front() == 3 ) ) ){
                q.push_front(2);
                c--;
                continue;
            }
            if( ( q.empty() || ( q.back() == 1 || q.back() == 3 ) ) ){
                q.push_back(2);
                c--;
                continue;
            }
            break;
        }
        break;
    }

    if( a || b || c || d ){ cout << "NO"; return 0; }

    cout << "YES\n";
    while( !q.empty() ){
        cout << q.front() << ' ';
        q.pop_front();
    }
    cout << '\n';

    return 0;
}