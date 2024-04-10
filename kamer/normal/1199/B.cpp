    #include <iostream>
    #include <iomanip>
    
    using namespace std;
    
    int main(void) {
        int h, l;
        std::cin >> h >> l;
        cout << fixed << setprecision(10);
        std::cout << (1.0 * l / (2.0 * h) * l - 1.0 * h / 2.0);
        return 0;
    }