#include <iostream>

using namespace std;

int main() {
    int origheight, origweight, s1h, s1w, s2h, s2w;
    cin >> origweight >> origheight >> s1w >> s1h >> s2w >> s2h;
    while(origheight!=0) {
        origweight+=origheight;
        if(origheight==s1h)
            origweight-=s1w;
        if(origheight==s2h)
            origweight-=s2w;
        if(origweight<0)
            origweight=0;
        origheight-=1;
    }
    cout << origweight << '\n';
}