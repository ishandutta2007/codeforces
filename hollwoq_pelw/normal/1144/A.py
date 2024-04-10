for __ in range(int(input())):
    s = sorted([ord(a)-97 for a in input()])
    flag = True
    for i in range(len(s)-1):
        if s[i+1]-s[i]!=1:
            flag = False
            break
    if flag: print("Yes")
    else: print("No")