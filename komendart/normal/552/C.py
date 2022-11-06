def main():
    w, m = [int(i) for i in input().split()]
    
    if w == 2:
        print("YES")
        return
    
    s = 0
    for i in range(21):
        for sign in range(-1, 2):
            if (m - s - sign * w ** i) % w ** (i + 1) == 0:
                s += sign * w ** i
                break
    
    if abs(s) == m:
        print("YES")
    else:
        print("NO")
    
main()