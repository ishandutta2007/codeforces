tc = int(input())

for z in range(tc):
    
    n = int(input())
    s = input()
    q = int(s)
    
    t = 0
    
    if s[0] == '9':
        l = []
        for i in range(n + 1):
            l.append('1')
        t = int(''.join(l))
    else:
        l = []
        for i in range(n):
            l.append('9')
        t = int(''.join(l))
    
    print(t - q)