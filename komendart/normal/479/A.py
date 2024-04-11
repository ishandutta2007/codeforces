def main():
    a, b, c = [int(input()) for i in range(3)]
    
    print(max(a * b * c, (a + b) * c, a * (b + c), a + b + c))
    
main()