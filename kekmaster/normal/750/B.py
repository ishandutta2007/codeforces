def main():
    MAXH = 20000
    n = int(input())
    h = 0
    for i in range(n):
        dist, d = input().split()
        dist = int(dist)
        if d in ('West', 'East'):
            if h == 0 or h == MAXH:
                print('NO')
                return
            continue
        if d == 'North':
            h -= dist
        elif d == 'South':
            h += dist
        if h < 0 or h > MAXH:
            print('NO')
            return
    print('YES' if h == 0 else 'NO')

 
if __name__=='__main__':
    main()