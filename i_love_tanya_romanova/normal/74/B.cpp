# include <iostream>
# include <vector>
# include <cassert>
# include <cstdio>
 
    using namespace std;
 
    void moveContr(int& pos, bool& dir, const int& n)
    {
        if (dir == true)
        {
            ++pos;
            if (pos == n) dir = false;
        }
        else
        {
            --pos;
            if (pos == 1) dir = true;
        }
    }
 
    bool moveGamer(int& gam, const int& contr, bool& dir, const int& n)
    {
        if (gam == 1 || gam == n)
        {
            return !(gam == contr);
        }
        else
        {
            dir ? ++gam:--gam;
            return true;
        }
    }
 
    bool getDirection()
    {
        string str;
        cin >> str >> str; cin.get();
        return (str == "tail");
    }
 
    int main()
    {
        int n, gamer, controller;
        cin >> n >> gamer >> controller;
        bool direction = getDirection(); // true = 1 .. n
       
        char ch;
        bool escape = true;
        int pas=0;
        while (cin>>ch){if (escape==0)break;if (ch=='3')break;++pas;
            moveContr(controller, direction, n);
           
            if (ch == '1')
            {
                if (cin.peek() == '1' || cin.peek() == '0')
                {
                    gamer = (direction ? (controller == 1 ? n:1):(controller == n ? 1:n));              
                }
            }  
            else
            {
                escape = moveGamer(gamer, controller, direction, n);
            }  
        }
       
        if (escape)
        {
            cout << "Stowaway";
        }
        else
        {
            cout << "Controller " << pas;
        }
       cin.get();cin.get();
        return 0;
    }