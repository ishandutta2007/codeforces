def main():
    n = int(input())
    s = input()
    
    b, g, r = [s.count(i) for i in "BGR"]
    
    if min(b, g, r) > 0:
        print("BGR")
        return
    if max(b, g, r) == n:
        if b == n: print("B")
        if g == n: print("G")
        if r == n: print("R")
        return
    if max(b, g, r) == 1:
        if b == 0: print("B")
        if g == 0: print("G")
        if r == 0: print("R")
        return
    if max(b, g, r) == n - 1:
        if b == n - 1: print("GR")
        if g == n - 1: print("BR")
        if r == n - 1: print("BG")
        return 
    
    print("BGR")
    
    
main()