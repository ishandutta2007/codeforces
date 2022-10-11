s=input()
d="AB"
if not "AB" in s or not "BA" in s:
    print("NO")
else:
    g=s[s.index(d)+2:]
    d=d[1]+d[0]
    if d in g:
        print("YES")
    else:
        g=s[s.index(d)+2:]
        d=d[1]+d[0]
        if d in g:
            print("YES")
        else:
            print("NO")