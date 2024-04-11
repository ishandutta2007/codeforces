def main():
    days = [-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    
    n, _, t = input().split()
    t = t[0]
    n = int(n)
    
    d = 5
    m = 1
    num = 1
    res = 0
    while True:
        if t == "w" and d == n or t == "m" and num == n:
            res += 1
        d = d % 7 + 1
        num += 1
        if num > days[m]:
            num = 1
            m += 1
            if m == 13:
                break
    print(res)
    
    
main()