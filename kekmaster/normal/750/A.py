def main():
    n, k = map(int, input().split())
    t = k
    for i in range(n + 1):
        t += 5 * (i + 1)
        if t > 240:
            print(i)
            return
    print(n)

 
if __name__=='__main__':
    main()