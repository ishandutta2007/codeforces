def main():
    n = int(input())
    x = 0
    for i in range(n):
        a = input()
        if(a[1]=='+'):
            x += 1
        else:
            x -= 1
    print(x)

if __name__ == '__main__':
    main()