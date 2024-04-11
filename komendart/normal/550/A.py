def main():
    import sys
    
    s = sys.stdin.read().strip()
    n = len(s)
    
    result = False
    flag = False
    i = 0
    while i < n - 1:
        if not flag and s[i: i + 2] == "AB":
            flag = True
            i += 2
        elif flag and s[i: i + 2] == "BA":
            result = True
            break
        else:   
            i += 1
    flag = False
    i = 0
    while i < n - 1:
        if not flag and s[i: i + 2] == "BA":
            flag = True
            i += 2
        elif flag and s[i: i + 2] == "AB":
            result = True
            break
        else:   
            i += 1

    print("YES" if result else "NO")

main()